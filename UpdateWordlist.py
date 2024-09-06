import requests

with open("./WordList.txt", "wb") as f:
    f.write(requests.get("https://raw.githubusercontent.com/UsernameIsNotAvailableBruh/JavaWordleFinder/main/WordList.txt").content)

