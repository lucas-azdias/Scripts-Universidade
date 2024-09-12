#!/usr/bin/python3

from requests import get, patch
from sys import argv, stderr


if __name__ == "__main__":
    if len(argv) < 2:
        print(f"USO: {argv[0]} <URL> <msg>", file=stderr)
        exit(1)
    
    url = argv[1]
    conta = argv[2]
    valor = argv[3]

    r = patch(url + "/contas/deposito/" + valor, headers={"conta": conta}).json()
    print("Created:", r["created"])

    r = patch(url + "/contas/saque/" + valor, headers={"conta": conta}).json()
    print("Done:", r["done"])

    r = get(url + "/contas", headers={"conta": conta}).json()
    print("Saldo:", r["saldo"])
