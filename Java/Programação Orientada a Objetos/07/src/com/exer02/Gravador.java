package com.exer02;

import java.io.FileOutputStream;
import java.io.ObjectOutputStream;

public class Gravador {
	
	public static void main(String[] args) {
		Empresa empresa = new Empresa("ABC LTDA.");
		
		empresa.addFuncionario(new Pessoa("Julia", 23));
		empresa.addFuncionario(new Pessoa("Gustavo", 34));
		
		Gravador.gravar(empresa, "files/data.dat");
	}
	
	public static void gravar(Object object, String path) {
		try {
			FileOutputStream file = new FileOutputStream(path);
			ObjectOutputStream stream = new ObjectOutputStream(file);
			
			stream.writeObject(object);
			stream.close();
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}

}
