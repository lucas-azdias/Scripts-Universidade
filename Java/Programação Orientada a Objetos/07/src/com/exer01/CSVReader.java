package com.exer01;

import java.io.FileReader;
import java.io.IOException;
import java.io.BufferedReader;

public class CSVReader {
	
	private String[] data;
	private int lineCounter, columnCounter;
	
	public static void main(String[] args) {
		CSVReader csv = new CSVReader("files/data.csv");
		
		System.out.println(csv.toString());
	}
	
	public CSVReader(String path) {
		try {
			BufferedReader buffer = new BufferedReader(new FileReader(path));

			String line;
			while ((line = buffer.readLine()) != null) {
				lineCounter++;
				
				int length = line.split(",").length;
				if (columnCounter < length) {
					columnCounter = length;
				}
			}
			buffer.close();
			
			data = new String[lineCounter * columnCounter];
			
			buffer = new BufferedReader(new FileReader(path));
			int i = 0;
			while ((line = buffer.readLine()) != null) {
				String[] columns = line.split(",");
				for (int j = 0; j < columns.length; j++) {
					data[i * columnCounter + j] = columns[j];
				}
				i++;
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public String toString() {
		String text = "";
		
		for (int i = 0; i < lineCounter; i++) {
			if (!(i == 0)) {
				text += "\n";
			}
			for (int j = 0; j < columnCounter; j++) {
				if (!(j == 0)) {
					text += ",";
				}
				text += data[i * columnCounter + j];
			}
		}
		
		return text;
	}

}
