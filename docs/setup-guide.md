# Setup Guide

This guide helps students verify that their machine is ready for the internship.

## Required Software

Install or verify the following:

* Git
* Visual Studio Code or another editor
* Python 3.11 or newer
* C++ compiler
* GitHub account access

## Windows Verification Commands

Run these commands in PowerShell:

```powershell
git --version
python --version
code --version
g++ --version
```

If `g++` is not available, you may be using MSVC instead. In that case, open the Visual Studio Developer PowerShell and run:

```powershell
cl
```

## Git First-Time Setup

Students should configure Git once:

```powershell
git config --global user.name "Your Name"
git config --global user.email "your.email@example.com"
git config --global init.defaultBranch main
```

Check the values with:

```powershell
git config --global --list
```

## Recommended VS Code Extensions

These are useful but not mandatory:

* Python
* C/C++
* GitLens
* Error Lens

## GitHub Access Checklist

Students should be able to:

* sign in to GitHub in a browser
* access the internship repository
* create branches in the repository or a fork
* open a pull request

## Common Problems

### `python` is not recognized

Python is not installed or not added to `PATH`. Reinstall Python and enable the `Add Python to PATH` option.

### `code` is not recognized

In VS Code, open the Command Palette and run `Shell Command: Install 'code' command in PATH` if available, or reinstall VS Code with the PATH option enabled.

### `g++` is not recognized

Install a compiler such as MinGW-w64 or use the Visual Studio C++ build tools.

### Git asks for login repeatedly

Use GitHub Desktop or Git Credential Manager, or sign in through VS Code.

## Day 1 Done Definition

The machine is ready when the student can:

* open the repository in an editor
* run Git commands successfully
* run a Python script
* compile or run a simple C++ program
* push a branch to GitHub
