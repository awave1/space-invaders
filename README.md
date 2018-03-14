# Space Invaders

## Authors: Artem Golovin, Daniel Artuso

Space Invaders game implemented in C and m68k assembly

## Project Overview

Each stage has similar folder structure.

```bash
.
├── bin                 # object files
├── makefile            # project makefile
└── src                 # all source files
    ├── asm             # assembly files
    │   ├── clear_ga.s
    │   └── clear_qk.s
    ├── include         # header files for both c and assembly
    │   ├── clear_ga.h
    │   ├── clear_qk.h
    │   ├── const.h
    │   ├── event.h
    │   ├── font.h
    │   ├── model.h
    │   ├── raster.h
    │   ├── render.h
    │   ├── space.h
    │   ├── sprites.h
    │   └── types.h
    ├── event.c
    ├── font.c
    ├── model.c
    ├── raster.c
    ├── render.c
    ├── space.c
    └── sprites.c
```

All `.o` files are compiled into `bin` directory and `.tos` executable is saved in the root of stage.

### Compilation Process
If no previous `.o` files or `.tos` executables were compiled in the stage folder, to comile the game, simply run:

```bash
make
```

For future compilations, run the following command:

```bash
Rm bin\*.o ; Rm *.tos ; make
```

## Notes, missing features, and known bugs

The latest changes are located in `stage6` folder.
**Things that are not implemented yet**:

* Wave functionality - At this moment there is only one wave in the game and the game is finished when all aliens are destroyed
* Aliens do not change their speed as the game progresses
* Shot delay for aliens is not implemented yet

**Known bugs**:

* If `ctrl-c` is pressed during the game, the Atari ST VM might freeze and will require a reboot. Instead, use `esc` to stop the game.
