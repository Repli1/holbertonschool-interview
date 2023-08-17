#!/usr/bin/python3
"""Function that determines if a configuration can be totally opened"""


def canUnlockAll(boxes):
    def recursion(box):
        opened_boxes[box] = True
        for key in boxes[box]:
            if key < len(boxes) and not opened_boxes[key]:
                recursion(key)

    opened_boxes = [False] * len(boxes)
    recursion(0)
    return all(opened_boxes)
