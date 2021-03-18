from typing import List, Tuple

import numpy as np
from matplotlib import pyplot as plt


def read_instruction(command: str) -> List[int]:
    coord = [0, 0]
    direction = command[0]
    distance = int(command[1:])
    if direction == "R":
        coord[0] += distance
    elif direction == "L":
        coord[0] -= distance
    elif direction == "U":
        coord[1] += distance
    elif direction == "D":
        coord[1] -= distance
    else:
        raise ValueError("Unknown direction!")
    return coord


def calc_turns(instruction: List[str]) -> List[List[int]]:
    current_coord = [0, 0]
    path = [current_coord[:]]
    for command in instruction:
        x_step, y_step = read_instruction(command)
        current_coord[0] += x_step
        current_coord[1] += y_step
        path.append(current_coord[:])
    return path


def calc_grid_path(instr: List[str]) -> List[List[int]]:
    current_coord = [0, 0]
    grid_path = []
    for command in instr:
        x_step, y_step = read_instruction(command)
        new_coord = [current_coord[0] + x_step, current_coord[1] + y_step]
        if x_step == 0:
            if new_coord[1] > current_coord[1]:
                grid_path += [(current_coord[0], y)
                              for y in range(current_coord[1] + 1, new_coord[1] + 1)]
            else:
                grid_path += [(current_coord[0], y)
                              for y in range(current_coord[1] - 1, new_coord[1] - 1, -1)]
        else:
            if new_coord[0] > current_coord[0]:
                grid_path += [(x, current_coord[1])
                              for x in range(current_coord[0] + 1, new_coord[0] + 1)]
            else:
                grid_path += [(x, current_coord[1])
                              for x in range(current_coord[0] - 1, new_coord[0] - 1, -1)]
        current_coord = new_coord[:]
    return grid_path


def day3(instr: List[List[str]], *, show_wires: bool = False):
    if False:
        wires = []
        for i in instr:
            wires.append(calc_turns(i))
        wires = np.asarray(wires, dtype=int)
        plt.figure("Jumble of wires")
        for wire in wires:
            plt.plot(wire[:, 0], wire[:, 1])
        plt.show()
    wires = []
    for i in instr:
        wires.append(calc_grid_path(i))

    print(f"{'=' * 20} PART 1 {'=' * 20}")
    intersections, closest_intersection = day3_part1(wires)
    print(
        f"Manhattan distance of closest intersection = {closest_intersection}")

    print(f"{'=' * 20} PART 2 {'=' * 20}")
    shortest_path = day3_part2(wires, intersections)
    print(f"Shortest path to intersection = {shortest_path}")


def day3_part1(wires: List[List[List[int]]]) -> Tuple[List[List[int]], int]:
    wires_unique_location = iter(map(set, wires))  # Ignore self crossings
    intersections = list(set.intersection(*wires_unique_location))
    manhattan_dists = np.sum(np.abs(np.asarray(intersections)), axis=1)
    return intersections, min(manhattan_dists)


def day3_part2(wires: List[List[List[int]]], intersections: List[List[int]]) -> int:
    intersection_idxs = []
    for crossing in intersections:
        idx = []
        for wire in wires:
            idx.append(wire.index(crossing))
        intersection_idxs.append(idx)
    # Add 2 to include intersection
    units_to_intersection = np.sum(np.asarray(intersection_idxs), axis=1) + 2
    return min(units_to_intersection)


if __name__ == "__main__":
    with open("input.txt", "r") as f:
        instructions = []
        for line in f:
            instructions.append(line.split(","))
    # Extend the lists to equal length to allow for conversion to ndarray
    max_instr = max(map(len, instructions))
    for i in instructions:
        n_i = len(i)
        if n_i < max_instr:
            i += (["R0"]*(max_instr - n_i))
    day3(instructions, show_wires=True)
