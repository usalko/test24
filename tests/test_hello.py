import test24
from test24._test24_impl import *


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

    def test_base_parameters(self, capsys):
        with capsys.disabled():
            base_parameters = BaseParameters()
            print(f'Initial excludes are: {base_parameters.exclude}')
            base_parameters.exclude = ['None']
            print(f'After setup excludes are: {base_parameters.exclude}')