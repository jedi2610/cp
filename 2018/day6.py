from collections import defaultdict
file = open("input", "r")
points = [[int(s) for s in line.rstrip().split(",")]
          for line in file.readlines()]

area = defaultdict(lambda: 0)
infinite = set()

# manhattan distance function


def dist(a, b):
    return abs(a[0]-b[0])+abs(a[1]-b[1])


#xr = x_range, yr = y_range
xr = [i for i in range(min([a[0] for a in points]),
                       max([a[0] for a in points])+1)]
yr = [i for i in range(min([a[1] for a in points]),
                       max([a[1] for a in points])+1)]

# for part 2
within = 0

for y in yr:
    # check vertical edges
    edge_y = y == yr[0] or y == yr[-1]
    for x in xr:
        # check horizontal edges
        edge_x = x == xr[0] or x == xr[-1]
        # map all points to an array of [distance, point as string]
        d = sorted(map(lambda p: [dist(p, [x, y]), str(p)], points))
        # print(d[0][0], d[1][0])
        # if closest distance is single closest distance (not duplicate)
        if d[0][0] != d[1][0]:
            area[d[0][1]] += 1
        # if on any of the edges it is infinite because it will extend infinitely
        if edge_x or edge_y:
            infinite.add(d[0][1])
        # if sum distances is smaller than 10000, its within the region (part2)
        within += sum([a[0] for a in d]) < 10000

# print max area that is not infinite
print(max([x[1] for x in area.items() if str(x[0]) not in infinite]))
print(within)

# from collections import defaultdict

# # SICP inspired me to get 'streamy' with this one


# def manhattan_distance(x1, y1, x2, y2):
#     return abs(x1 - x2) + abs(y1 - y2)


# def coords_limits(coords):
#     min_x = min(coords, key=lambda c: c[0])[0]
#     max_x = max(coords, key=lambda c: c[0])[0]
#     min_y = min(coords, key=lambda c: c[1])[1]
#     max_y = max(coords, key=lambda c: c[1])[1]

#     return ((min_x, max_x), (min_y, max_y))


# def gen_locations(x_lims, y_lims):
#     for x in range(x_lims[0], x_lims[1] + 1):
#         for y in range(y_lims[0], y_lims[1] + 1):
#             yield (x, y)


# def gen_locations_coords(coords):
#     x_lims, y_lims = coords_limits(coords)
#     for x, y in gen_locations(x_lims, y_lims):
#         for cx, cy in coords:
#             yield ((x, y), (cx, cy))


# def gen_locations_coords_dists(coords):
#     for (x, y), (cx, cy) in gen_locations_coords(coords):
#         d = manhattan_distance(cx, cy, x, y)
#         yield ((x, y), (cx, cy), d)


# def part_1(coords):
#     closest_coord_map = {}
#     closest_coord_dists = defaultdict(lambda: float("inf"))
#     for (x, y), (cx, cy), d in gen_locations_coords_dists(coords):
#         closest = closest_coord_dists[(x, y)]
#         if d < closest:
#             closest_coord_map[(x, y)] = (cx, cy)
#             closest_coord_dists[(x, y)] = d
#         elif d == closest and closest_coord_map[(x, y)] != (cx, cy):
#             closest_coord_map[(x, y)] = None

#     x_lims, y_lims = coords_limits(coords)
#     coords_areas = defaultdict(int)
#     for xy, coord in closest_coord_map.items():
#         if coord is None:
#             continue
#         if xy[0] in x_lims or xy[1] in y_lims:
#             coords_areas[coord] = float("-inf")
#         coords_areas[coord] += 1
#     return max(coords_areas.values())


# def part_2(coords):
#     total_dists_to_coords = defaultdict(int)
#     for (x, y), (cx, cy), d in gen_locations_coords_dists(coords):
#         total_dists_to_coords[(x, y)] += d
#     return len([l for l, d in total_dists_to_coords.items() if d < 10000])


# def main(puzzle_input_f):
#     lines = puzzle_input_f.read().split("\n")
#     coords = [
#         tuple([int(s.strip()) for s in line.split(",")]) for line in lines if line
#     ]

#     print("Part 1: ", part_1(coords))
#     print("Part 2: ", part_2(coords))


# if __name__ == "__main__":
#     with open("input.txt") as f:
#         main(f)
