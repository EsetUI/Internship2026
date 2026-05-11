# Git Cheat Sheet

This is a practical command list for daily internship work.

## Clone The Repository

```powershell
git clone <repository-url>
cd Internship2026
```

## Check Current State

```powershell
git status
git branch
git log --oneline --decorate --graph -10
```

## Create And Switch To A Branch

```powershell
git switch -c student/your-name-day-1
```

## Save Work

```powershell
git add .
git commit -m "Add first Python exercise"
git push -u origin student/your-name-day-1
```

## Update Your Branch From Main

```powershell
git switch main
git pull
git switch student/your-name-day-1
git merge main
```

## Inspect Changes

```powershell
git diff
git diff --staged
```

## Undo A File Before Commit

```powershell
git restore path/to/file
```

## Unstage A File

```powershell
git restore --staged path/to/file
```

## Good Commit Messages

Good examples:

* `Add number statistics Python script`
* `Fix C++ input validation`
* `Update Day 2 branch workflow notes`

Avoid messages like:

* `update`
* `fix`
* `asdf`

## Pull Request Checklist

Before opening a pull request, check:

* the code runs locally
* the changed files are relevant
* the commit message is clear
* the pull request description explains what changed

## Suggested Beginner Workflow

1. Pull the latest `main` branch.
2. Create a new branch.
3. Make a small change.
4. Run the program.
5. Commit the change.
6. Push the branch.
7. Open a pull request.
8. Apply review feedback.
