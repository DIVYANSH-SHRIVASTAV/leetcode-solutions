import requests
import base64

# 🔑 Config


# LeetCode GraphQL endpoint
LEETCODE_API = "https://leetcode.com/graphql"

# Step 1: Recent Submissions Query
recent_query = """
query recentAcSubmissions($username: String!) {
  recentSubmissionList(username: $username, limit: 5) {
    title
    titleSlug
    lang
    timestamp
    statusDisplay
  }
}
"""

# Step 2: Difficulty Fetch Query
difficulty_query = """
query getQuestionDetail($titleSlug: String!) {
  question(titleSlug: $titleSlug) {
    difficulty
  }
}
"""

headers = {"Content-Type": "application/json"}

# Fetch recent submissions
res = requests.post(LEETCODE_API, json={"query": recent_query, "variables": {"username": LEETCODE_USERNAME}}, headers=headers)
print("Status Code:", res.status_code)
data = res.json()

if "data" not in data or "recentSubmissionList" not in data["data"]:
    print("❌ Error: Could not fetch submissions")
    exit()

submissions = data["data"]["recentSubmissionList"]

# Filter accepted ones
accepted = [sub for sub in submissions if sub["statusDisplay"] == "Accepted"]

problems = []
for sub in accepted:
    slug = sub["titleSlug"]

    # Step 2 -> Get difficulty
    res2 = requests.post(LEETCODE_API, json={"query": difficulty_query, "variables": {"titleSlug": slug}}, headers=headers)
    diff_data = res2.json()

    difficulty = diff_data["data"]["question"]["difficulty"] if "data" in diff_data else "Unknown"

    problems.append({
        "title": sub["title"],
        "slug": slug,
        "lang": sub["lang"],
        "timestamp": sub["timestamp"],
        "difficulty": difficulty
    })

print("📊 Final Solved Problems:", problems)

# -----------------------
# 🔥 Upload to GitHub
# -----------------------
GITHUB_API = f"https://api.github.com/repos/{MY_GITHUB_REPO}/contents/README.md"

# Format README content
content = "# 🚀 LeetCode Solutions\n\n"
for p in problems:
    content += f"- [{p['title']}](https://leetcode.com/problems/{p['slug']}/) | {p['lang']} | {p['difficulty']} | ⏰ {p['timestamp']}\n"

encoded_content = base64.b64encode(content.encode()).decode()

# Get current SHA (for updating file)
sha = None
res = requests.get(GITHUB_API, headers={"Authorization": f"token {MY_GITHUB_TOKEN}"})
if res.status_code == 200:
    sha = res.json()["sha"]

# Push file to GitHub
res = requests.put(GITHUB_API, headers={"Authorization": f"token {MY_GITHUB_TOKEN}"}, json={
    "message": "📝 Update LeetCode solutions",
    "content": encoded_content,
    "sha": sha
})

if res.status_code in [200, 201]:
    print("✅ README.md updated on GitHub!")
else:
    print("❌ GitHub Push Failed:", res.json())
