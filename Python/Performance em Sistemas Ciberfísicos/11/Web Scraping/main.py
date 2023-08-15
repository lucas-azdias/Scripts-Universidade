from requests import get
from threading import Thread


if __name__ == "__main__":
    directory = "download/"
    path_prefix = "https://pt.wikipedia.org/wiki/"
    path_sufixes = [
        "Ciclone_Mocha",
        "Indochina",
        "Brasil",
        "Inglaterra",
        "França",
        "Rússia",
        "Portugal",
        "Espanha"
    ]

    def download_page(id, path_prefix, path_sufix):
        with open(directory + path_sufix + ".html", "w", encoding="utf-8") as file:
            print(f"Thread {id} começou a baixar!")
            file.write(get(path_prefix + path_sufix).text)
            print(f"Thread {id} terminou de baixar!")
            file.close()
    
    threads = []
    for i, path_sufix in enumerate(path_sufixes):
        threads.append(Thread(target=download_page, args=(i, path_prefix, path_sufix)))

    for thread in threads:
        thread.start()

    for thread in threads:
        thread.join()
