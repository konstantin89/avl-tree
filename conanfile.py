from conans import ConanFile, CMake

class HelloConan(ConanFile):
    name = "AvlTreeLib"
    version = "1.0"
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake"

    def source(self):
        self.run("git clone https://github.com/konstantin89/avl-tree-lib")
        self.run("cd avl-tree-lib")

    def build(self):
        cmake = CMake(self)
        cmake.configure(source_folder=".")
        cmake.build()

    def build_requirements(self):
        self.build_requires("catch2/3.4.0")