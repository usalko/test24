from test24._test24_impl import *

import test24


class TestHello:

    def test_hello(self, capsys):
        with capsys.disabled():
            help(test24)
            print('#====================================================')
            # print('\n'.join([m for m in dir(test24)]))
            # print('#====================================================')
            print('\n'.join([m for m in dir(test24._test24_impl)]))
            print('#====================================================')

            print(hello())
            print(hello2())
2