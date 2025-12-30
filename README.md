# Game engine by man who has no time to develop game engines.
Name is Ryswick until someone thinks of something cooler.

# Big baller manifesto, of sorts
- AI use only for the most detestable mundane tasks no human should devote time to.
  - An example of this can be seen in this project's `.gitignore`.
  - Friction fosters creativity and growth. Too little friction and you're left with neither.
  - Also, whenever Microsoft decides to give me free tab-complete, I don't turn it off.
- **Code-first** engine
- No ceremonies.
- Cross platform
  - This means a robust API-agnostic renderer interface must be implemented.
- Plug 'n' play with all scripting languages (within reason)
  - If you want to use Lua, you should be able to.
  - If you want to use Python, you should be able to.
  - If you want to use Squirrel, you should be able to.
  - If you want to use Wren, you should be able to.
  - If you want to use C#, you shouldn't be able to.
  - This means the requirements and typical behavior of in-engine use of scripting languages must be thought out and generically implemented.
- No "plugins" should be supported.
  - If you want to add a feature, implement the feature into the engine.
    - There is no point in developing a wrapper around modularity when you can just write the software to do the thing.
- All tooling should follow the [Unix Philosophy](https://en.wikipedia.org/wiki/Unix_philosophy)
- All tooling should be written and compiled for all platforms, within reason.
- All code that is not overtly self-expplanatory is to be well-documented.
  - Boilerplate is not this.
  - Unless you are reciting [FISR-level incantations](https://github.com/id-Software/Quake-III-Arena/blob/dbe4ddb10315479fc00086f08e25d968b4b43c49/code/game/q_math.c#L561), **do not comment line by line what code is doing**. Tell the reader *why* you wrote it, if deemed helpful.
- All large decisions should be viewed as forks.
  - If making a decision and presented with more than one option, follow each until desired result is achieved.
    - After deciding which option to pick, but before starting work, create a new branch, such that we can return to the same state if this option doesn't pan out.
- Code should be written with the understanding that *there will be someone who comes after you*.
  - Plan it out. Write good software. Treat the person who comes next to a showcase of your work in a way that helps them move forward.

# Building
## macOS
If on macOS, symlink `compile_commands.json` from `build/ninja` to project root.

`ln -sf build/ninja/compile_commands.json compile_commands.json`

- Build configuration supports both Ninja and Xcode generators.
- I have no idea what I'm doing with macOS. If you know how to do things better, please god help me.

## Windows
Will need to change `C:/Users/dev/vcpkg` to your vcpkg root in `Makefile`.
```
make configure
make run-debug
```

## Linux
Linux support will be locked arbitrarily to only support omarchy 
<img src="https://media.tenor.com/KL1ova4-26cAAAAm/kappa.webp" width="24" style="margin: 0px 0rem -0.5rem">

# Very near future TODOs
- Textures
- 3D
- Asset storage and loading system
- Linter configuration to enforce standards
- OpenGL
- Save file support
  - We're barely rendering triangles at the moment, but after realizing many modern save files take up 25mb~, I'm set on doing the opposite.
