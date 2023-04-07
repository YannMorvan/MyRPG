# REQUIREMENTS

### MANDATORY

- [ ] The player needs to have characteristics
- [ ] The player can fight enemies AND the characteristics impact the fights results 
- [ ] The player have an inventory which can contain a limited set of items
- [ ] The player can earn experience by winning fights and/or accomplishing specific actions
- [ ] The player can level up thanks to experience AND upgrading its characteristics
- [ ] The game contains NPC
- [ ] The game contains at least one quest
- [ ] The game contains a how to play system at the very beginning

### TECHNICAL REQUIREMENTS

- [ ] A collision system including moving and static elements with different shapes.
- [X] Camera movements (zoom, translation, rotation).
- [X] 3D effects (depth scaling, isometric projection. . . ).
- [X] Buttons must have at least 3 differents state
- [ ] Saving system

### MUST

#### General

- [X] The window may be closed using events,
- [X] The windows may have differents mode:
    - [X] Window mode
    - [X] Fullscreen
- [X] The windows may have differents resolutions, at least two (1920x1080, and an other)
- [X] The game manages inputs from the mouse click and keyboard,
- [X] The game contains animated sprites rendered thanks to sprite sheets,
- [ ] Animations in your program are frame rate independent,
- [X] Animations and movements in your program are timed by clocks.

#### Main menu

- [ ] Must contain at least these options
    - [ ] Start the game
    - [ ] Resume game (grayed out if not possible)
    - [ ] Settings
    - [ ] Quit the game
- [ ] The settings option must contain
    - [ ] Sound and music volume options
    - [ ] A window size and resolution options

#### In game menu

- [ ] Must be accessible by pressing the Escape key
    - [ ] Must contain at least these options
    - [ ] Character options
      - [ ] equipment and inventory management
      - [ ] characteristics management
    - [ ] Saving
    - [ ] Loading
    - [ ] Settings
      - [ ] the same that main menu
      - [ ] commands list

### SHOULD

- [X] Splash screen at the beginning
- [ ] Command edit into the in game menu
- [ ] As much information as possible about the game should be stored in a configuration file.
- [ ] The game should have an advanced collision system to manage complex fighting.
- [ ] The game should contain simple particle system:
    - [ ] with at least 2 types of particle,
    - [ ] particle effects (changing colors, scaling, bouncing, fading) to simulate realistic environment (wind, fire, rain, snow. . . ).

### COULD

- [ ] Have a skill tree, unlocking different abilities (active and passive).
- [ ] Have a complete particle engine.
- [ ] Use scripting to describe entities.
- [ ] Have a map editor.
