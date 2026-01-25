0) Go to your project folder
cd ~/Desktop/my_project

1) Create README + .gitignore (optional but recommended)
touch README.md .gitignore


Example .gitignore for C/C++ (quick start):

cat << 'EOF' > .gitignore
/build
*.o
*.out
*.exe
*.log
EOF

2) Initialize git
git init

3) Make sure branch is main
git branch -M main

4) Create the repo on GitHub EMPTY

When you create it on GitHub, choose:

✅ Do NOT add README

✅ Do NOT add .gitignore

✅ Do NOT add LICENSE

(Empty remote avoids “fetch first” problems.)

5) Connect remote (origin)
git remote add origin https://github.com/USERNAME/REPO.git
git remote -v

6) First commit
git add .

git commit -m "Initial commit"

8) First push + set upstream
git push -u origin main


After this, next times you can do:

git add .
git commit -m "Some change"
git push
