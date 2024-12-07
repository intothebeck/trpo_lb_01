import subprocess


def run(a, b):
    return int(subprocess.check_output(['./build/00_add', str(a), str(b)], text=True))


if __name__ == "__main__":
    assert run(1, 1) == 2
    assert run(-1, 1) == 0
    assert run(-1, -1) == -2
    print('Success!')
