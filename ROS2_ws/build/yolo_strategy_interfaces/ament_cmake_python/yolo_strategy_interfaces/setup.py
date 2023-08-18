from setuptools import find_packages
from setuptools import setup

setup(
    name='yolo_strategy_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('yolo_strategy_interfaces', 'yolo_strategy_interfaces.*')),
)
