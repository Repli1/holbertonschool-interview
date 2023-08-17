#!/usr/bin/python3

def canUnlockAll(boxes):
    def recursion(box):
        opened_boxes[box] = True
        for key in boxes[box]:
            if not opened_boxes[key]:
                recursion(key)

    opened_boxes = [False] * len(boxes)
    recursion(0)
    return all(opened_boxes)