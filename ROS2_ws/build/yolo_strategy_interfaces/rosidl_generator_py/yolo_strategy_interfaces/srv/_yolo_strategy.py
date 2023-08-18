# generated from rosidl_generator_py/resource/_idl.py.em
# with input from yolo_strategy_interfaces:srv/YoloStrategy.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'update_position'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_YoloStrategy_Request(type):
    """Metaclass of message 'YoloStrategy_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('yolo_strategy_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'yolo_strategy_interfaces.srv.YoloStrategy_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__yolo_strategy__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__yolo_strategy__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__yolo_strategy__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__yolo_strategy__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__yolo_strategy__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class YoloStrategy_Request(metaclass=Metaclass_YoloStrategy_Request):
    """Message class 'YoloStrategy_Request'."""

    __slots__ = [
        '_send_position',
        '_update_position',
    ]

    _fields_and_field_types = {
        'send_position': 'uint8',
        'update_position': 'sequence<double>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.send_position = kwargs.get('send_position', int())
        self.update_position = array.array('d', kwargs.get('update_position', []))

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.send_position != other.send_position:
            return False
        if self.update_position != other.update_position:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def send_position(self):
        """Message field 'send_position'."""
        return self._send_position

    @send_position.setter
    def send_position(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'send_position' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'send_position' field must be an unsigned integer in [0, 255]"
        self._send_position = value

    @builtins.property
    def update_position(self):
        """Message field 'update_position'."""
        return self._update_position

    @update_position.setter
    def update_position(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'update_position' array.array() must have the type code of 'd'"
            self._update_position = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'update_position' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._update_position = array.array('d', value)


# Import statements for member types

# Member 'current_position'
# already imported above
# import array

# already imported above
# import builtins

# already imported above
# import math

# already imported above
# import rosidl_parser.definition


class Metaclass_YoloStrategy_Response(type):
    """Metaclass of message 'YoloStrategy_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('yolo_strategy_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'yolo_strategy_interfaces.srv.YoloStrategy_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__yolo_strategy__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__yolo_strategy__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__yolo_strategy__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__yolo_strategy__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__yolo_strategy__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class YoloStrategy_Response(metaclass=Metaclass_YoloStrategy_Response):
    """Message class 'YoloStrategy_Response'."""

    __slots__ = [
        '_current_position',
    ]

    _fields_and_field_types = {
        'current_position': 'sequence<double>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.current_position = array.array('d', kwargs.get('current_position', []))

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.current_position != other.current_position:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def current_position(self):
        """Message field 'current_position'."""
        return self._current_position

    @current_position.setter
    def current_position(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'current_position' array.array() must have the type code of 'd'"
            self._current_position = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'current_position' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._current_position = array.array('d', value)


class Metaclass_YoloStrategy(type):
    """Metaclass of service 'YoloStrategy'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('yolo_strategy_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'yolo_strategy_interfaces.srv.YoloStrategy')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__yolo_strategy

            from yolo_strategy_interfaces.srv import _yolo_strategy
            if _yolo_strategy.Metaclass_YoloStrategy_Request._TYPE_SUPPORT is None:
                _yolo_strategy.Metaclass_YoloStrategy_Request.__import_type_support__()
            if _yolo_strategy.Metaclass_YoloStrategy_Response._TYPE_SUPPORT is None:
                _yolo_strategy.Metaclass_YoloStrategy_Response.__import_type_support__()


class YoloStrategy(metaclass=Metaclass_YoloStrategy):
    from yolo_strategy_interfaces.srv._yolo_strategy import YoloStrategy_Request as Request
    from yolo_strategy_interfaces.srv._yolo_strategy import YoloStrategy_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
