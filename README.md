# AVL Tree Lib

## brief

AVL Tree Lib is modern C++ template implementation of AVL self balancing search tree algorithm.


## Building

``` bash
git clone https://github.com/konstantin89/avl-tree
cd avl-tree
mkdir build
cd build
conan install ..
conan build ..
```

## Running unit tests

``` bash
git clone https://github.com/konstantin89/avl-tree
cd avl-tree
cd build
conan install ..
conan build ..
./tests/bin/tests
```

## AVL Trees Theory

### Right rotation
![](img/right_rotation.png)

### Left rotation
![](img/left_rotation.png)

### Right Left rotation
![](img/right_left_rotation.png)

### Left Right rotation
![](img/left_right_rotation.png)
