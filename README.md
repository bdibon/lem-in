# lem-in
The goal of this project is to find the quickest way for a colony of N ants to cross any farm.

1. The farm will have two endpoints : start and end.
2. All the ants are stacked on start at the beginning.
3. An ant which is on a room (graph node) can only move to the neighbouring rooms.
4. An ant can only go through one edge during a turn.
5. There can be only one ant per room (except for start and end).

![Image of an ant farm](https://github.com/borisdibon/lem-in/blob/master/ant_colony.png?raw=true)

## Build
Run `make` in the root folder of the project will produce an executable `lem-in`.

## Help the ants
`lem-in` will read an ant farm from `stdin`, the ant farm is a text file which looks like this: 

* number_of_ants
* the_rooms
* the_links

```
2
1 0 2
##start
0 2 0
##end
4 2 6
2 4 2
3 4 4
0-1
0-2
2-3
3-4
4-1
```
`lem-in` will then return a formatted answer `Lx-y Lz-w Lr-o` where x, z and r represent the `ant id`; y, w, o represent the `room id`, every line break means the end of a turn. Thus `L1-2` means `ant 1` moved to `room 2`. 

```
L1-2
L1-3 L2-2
L1-1 L2-3 L3-2
L2-1 L3-3
L3-1
```
