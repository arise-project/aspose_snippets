package aspose_snippets.java;

import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        
        try {
			new Split_HTML().Execute();
    	}
    	catch (Expection ex) {
    		System.err.println(ex.toString());
    	}

        try {
			new Split_PDF().Execute();
    	}
    	catch (Expection ex) {
    		System.err.println(ex.toString());
    	}

        try {
			new Split_TXT().Execute();
    	}
    	catch (Expection ex) {
    		System.err.println(ex.toString());
    	}
    }
}