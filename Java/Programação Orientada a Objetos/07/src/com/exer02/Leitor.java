package com.exer02;

import java.io.FileInputStream;
import java.io.ObjectInputStream;

public class Leitor {
	
	public static void main(String[] args) {
		Empresa empresa = (Empresa) Leitor.ler("files/data.dat");
		
		System.out.println(empresa.toString());
	}
	
	public static Object ler(String path) {
		Object object = null;
		
		try {
			FileInputStream file = new FileInputStream(path);
			ObjectInputStream stream = new ObjectInputStream(file);
			
			object = stream.readObject();
			stream.close();
		}
		catch (Exception e) {
			e.printStackTrace();
		}
		
		return object;
	}

}
