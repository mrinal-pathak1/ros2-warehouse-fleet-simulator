import os
from glob import glob
from setuptools import setup

package_name = 'warehouse_simulator'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', glob('launch/*.py')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='mrinal',
    maintainer_email='mrinal@todo.todo',
    description='Warehouse simulator using ROS2',
    license='MIT',
    entry_points={
        'console_scripts': [
            'warehouse_map = warehouse_simulator.warehouse_map:main',
            'robot_agent = warehouse_simulator.robot_agent:main',
            'fleet_manager = warehouse_simulator.fleet_manager:main',
        ],
    },
)
