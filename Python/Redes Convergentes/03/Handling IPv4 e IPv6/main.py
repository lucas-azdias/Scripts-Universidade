# https://docs.python.org/3/library/ipaddress.html

from ipaddress import ip_address, IPv4Address, IPv6Address


def testaIPv4(IP: str) -> str:

    try:
        ip_obj = ip_address(IP)
        print(f'Global: {ip_obj.is_global}')
        print(f'Private: {ip_obj.is_private}')
        print(f'Link local: {ip_obj.is_link_local}')
        print(f'Loopback: {ip_obj.is_loopback}')
    except Exception as e:
        print(e)
        return "INVALIDO"

    try:
        if type(ip_obj) is IPv4Address:
            return "IPv4"
        elif type(ip_obj) is IPv6Address:
            return "IPv6"
        else:
            return "ERROR"

    except ValueError:
        return "Something bad happened!"


while True:
    ip = input('digite o endereco: ')
    print(testaIPv4(ip))
