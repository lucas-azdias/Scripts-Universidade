"""
Sistemas diferentes usam padrões diferentes de Endian-ness. Pior que
isso, informações trocadas via rede, entre sistemas e protocolos
diferentes, podem estar sendo manipuladas por sistemas diferentes.
Sua tarefa será descobrir os comandos em Python que permitem
determinar a Endian-ness do seu computador e estudar como o
módulo struct permite trocar a Endian-ness do buffer definido por:
buf = b'\x01\x00\x00\x00\x02\x00\x00\x00\x02\x00\x00\x00\x02\x00\x00\x00'
"""

import struct
import sys

if __name__ == "__main__":
    print(f"Meu computador possui uma endianness do tipo {sys.byteorder.upper()}")

    buf = struct.unpack("@4i", b'\x01\x00\x00\x00\x02\x00\x00\x00\x02\x00\x00\x00\x02\x00\x00\x00')

    big = struct.pack(">4i", *buf)  # Converte para big-endian
    lit = struct.pack("<4i", *buf)  # Converte para little-endian

    print(f"Em big-endian {big.hex()} e em little-endian {lit.hex()}")
