from test24._test24_impl import *

import test24


class TestHello:

    def test_info(self, capsys):
        with capsys.disabled():
            help(test24)
            print('#====================================================')
            # print('\n'.join([m for m in dir(test24)]))
            # print('#====================================================')
            print('\n'.join([m for m in dir(test24._test24_impl)]))
            print('#====================================================')

    def test_hello(self, capsys):
        with capsys.disabled():
            print(hello())

    def test_hello2(self, capsys):
        with capsys.disabled():
            print(hello2())

    def test_hello3(self, capsys):
        with capsys.disabled():
            print(hello3(['word1', 'word2', 'word3']))
