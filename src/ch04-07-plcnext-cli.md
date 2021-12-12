## PLCnext CLI

You previously used the PLCnext CLI to install the SDK that you have been using to build your C++ projects for the target. However, the PLCnext CLI does much more than that.

### Code Generation

- Generate source files for two different types of projects - in our case, we will just use acfproject (we will look at the other type later).
- Add templates for your own project types, if you want. (HOw TO USE THESE???)
- Add and remove components from a project

### Building

- Easily build for the required target(s)

The basic procedure is:

- New project - this generates component source code.
- Set target
- Add/Remove components if necessary.
- Edit Component source code
- Generate code (this generates Library source files)
- Build
- Deploy to target
- Test
- Go back to step 3 and repeat.

Note that you should not edit any code in the intermediate directory. This code is regenerated whenever the generate code command is executed, and at that point any manual changes will be lost.
