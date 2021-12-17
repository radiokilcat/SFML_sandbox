import subprocess
import os
import locale

def os_windows():
    return os.name == 'nt'


def os_linux():
    return not os_windows()


def os_current_file_path():
    return os.path.dirname(os.path.abspath(__file__))


def os_env():
    new_env = dict(os.environ)
    if not os_windows():
        new_env["CFLAGS"] = "-fPIC"
        new_env["CPPFLAGS"] = "-fPIC"
        add_path = "".join(chr(x) for x in subprocess.Popen("conan profile get env.CMAKE_PATH media", shell=True, stdout=subprocess.PIPE).stdout.read())[:-1]
        new_env["PATH"] = add_path + ":" + new_env["PATH"]
    return new_env


def path_to(path_list):
    return os.path.join(os_current_file_path(), *path_list)


def execute(command, raise_exception=True):
    p = subprocess.Popen(command, stderr=subprocess.PIPE, env=os_env())
    output, error = p.communicate()
    if p.returncode != 0 and raise_exception:
        raise ValueError("\n\n{}\n\ncommand: {}".format(error.decode(locale.getpreferredencoding()), ' '.join(command)))


execute(['conan', 'profile', 'new', '--detect', 'alex'], raise_exception=False)
execute(['conan', 'profile', 'update', 'settings.compiler.cppstd=20'], raise_exception=False)
