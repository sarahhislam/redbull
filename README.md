1️⃣ CHECK WHAT CHANGED

COPY & PASTE:
git status

WHAT IT DOES:
Shows which files were changed, added, or not tracked.

WHEN TO USE:
Use this before adding or committing to see what Git sees.

2️⃣ ADD ALL CHANGES

COPY & PASTE:
git add .

WHAT IT DOES:
Stages ALL modified and new files.

WHEN TO USE:
Use this when you're done editing and want everything included in the next commit.

3️⃣ ADD ONE FILE ONLY

COPY & PASTE:
git add filename

EXAMPLE:
git add main.cpp

WHAT IT DOES:
Stages only that file.

WHEN TO USE:
Use this if you don’t want to commit everything.

4️⃣ SAVE YOUR WORK (COMMIT)

COPY & PASTE:
git commit -m "Describe what you changed"

EXAMPLE:
git commit -m "Added logic gate implementation"

WHAT IT DOES:
Creates a snapshot of staged files and saves them locally.

WHEN TO USE:
After git add. This does NOT upload yet — it saves locally.

5️⃣ PUSH TO GITHUB (UPLOAD)

FIRST TIME ONLY COPY & PASTE:
git push -u origin main

AFTER FIRST TIME COPY & PASTE:
git push

WHAT IT DOES:
Uploads your commits to GitHub.

WHEN TO USE:
After committing when you want changes online.

6️⃣ GET LATEST VERSION FROM GITHUB

COPY & PASTE:
git pull origin main

WHAT IT DOES:
Downloads newest changes from GitHub and merges them into your local project.

WHEN TO USE:
Before starting work OR if teammates pushed updates.

7️⃣ CREATE A NEW BRANCH

COPY & PASTE:
git checkout -b branch-name

EXAMPLE:
git checkout -b feature-login

WHAT IT DOES:
Creates and switches to a new branch.

WHEN TO USE:
When starting a new feature or testing something separate from main.

8️⃣ SWITCH BRANCHES

COPY & PASTE:
git checkout main

WHAT IT DOES:
Switches back to the main branch (or any branch you name).

WHEN TO USE:
When you need to move between features.

9️⃣ SEE ALL BRANCHES

COPY & PASTE:
git branch

WHAT IT DOES:
Shows all branches and highlights the current one.

WHEN TO USE:
If you forget what branch you're on.

🔥 FULL DAILY WORKFLOW (ALWAYS DO THIS)

STEP 1 — Get latest version:
git pull origin main

STEP 2 — Make your changes

STEP 3 — Check changes:
git status

STEP 4 — Stage changes:
git add .

STEP 5 — Commit:
git commit -m "Clear description of what you changed"

STEP 6 — Upload:
git push

🧠 REMEMBER

add → commit → push
Pull before starting.
Push after finishing.




3️⃣ Add your changes

To add everything:

git add .

Or add one file:

git add filename
4️⃣ Commit (save locally)
git commit -m "Describe what you changed"

Example:

git commit -m "Updated README and fixed logic bug"

This saves your work locally (not online yet).

5️⃣ Push to GitHub (upload it)

If this is your first push ever:

git push -u origin main

After that, every time just use:

git push
🔥 The 3 Commands You Actually Need Most

When you're done working, just do:

git add .
git commit -m "Clear message about changes"
git push

How to run code from terminal in VScode?
g++ {filename} -o {a name for your executable}
./{the name for your executable}

That’s it.