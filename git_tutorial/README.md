---

# 📘 Git & GitHub — Console Guide

This guide explains how to work with Git and **GitHub** from the terminal:

* how to push (first time and next times)
* how to connect to a repository
* what the main commands do

Works on Linux / macOS.

---

## 1️⃣ How to push

### 🔹 First push (new project)

```bash
git init
git branch -M main
git remote add origin https://github.com/USERNAME/REPO.git
git add .
git commit -m "Initial commit"
git push -u origin main
```

**Explanation:**

* initializes git in the directory
* sets the main branch
* connects the remote repository
* creates the first commit
* sets upstream (`main → origin/main`)

---

### 🔹 Next pushes

```bash
git add .
git commit -m "Describe changes"
git push
```

After the first push, `git push` works without extra arguments.

---

### ⚠️ If files were edited on GitHub (README, .gitignore, etc.)

Before pushing, always pull first:

```bash
git pull --rebase origin main
```

---

## 2️⃣ How to connect to a repository

### 🔹 Option A — local folder already exists

```bash
git init
git remote add origin https://github.com/USERNAME/REPO.git
git remote -v
```

`origin` is just a **name (alias)** for the remote repository.

---

### 🔹 Option B — clone an existing repository (recommended)

```bash
git clone https://github.com/USERNAME/REPO.git
cd REPO
```

In this case:

* `origin` is created automatically
* `git init` is NOT required

---

## 3️⃣ Commands reference (command → what it does)

### 📂 Navigation

```bash
cd dir        # change directory
ls            # list files
pwd           # show current path
```

---

### 🧠 Git basics

```bash
git init                  # initialize git repository
git clone URL             # clone remote repository
git status                # show repository state
git remote -v             # show connected remotes
```

---

### 🧩 Staging & commits

```bash
git add file.txt          # add file to staging
git add .                 # add all changes
git commit -m "message"   # create a commit (snapshot)
```

---

### 🚀 Sync with GitHub

```bash
git push                  # send commits to remote
git pull                  # fetch + merge
git pull --rebase         # fetch + rebase (clean history)
git fetch                 # only write new commits , doesnt change the code in the local directory
```

---

### 🌿 Branches

```bash
git branch                # list branches
git branch -M main        # rename branch to main
git switch main           # switch branch
git checkout -b feature   # create and switch to new branch
```

---

### 🔁 Rebase

```bash
git rebase --continue     # continue rebase after conflicts
git rebase --abort        # cancel rebase
```

---

### 📦 Files & directories

```bash
mkdir src                 # create directory
touch README.md           # create file
git mv a b                # move or rename file
```

⚠️ Git does **not** track empty directories.
Use a placeholder file like `.gitkeep`.

---

### 🧹 Undo / temporary save

```bash
git restore file.txt      # discard file changes
git stash                # temporarily save changes
git stash pop            # restore saved changes
```

---

## 🧠 Mental model

```
edit → git add → git commit → git push
```

---

## ❗ Common mistakes

* pushing without committing
* using `git commit` during rebase
* working in detached HEAD
* expecting empty folders to be tracked

---

## ✅ Best practices

* create `README.md` and `.gitignore` locally
* first commit = **Initial commit**
* keep `main` stable
* use branches for features and experiments

---
