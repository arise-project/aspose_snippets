package aspose_snippets.java;

import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        
        try {
			new Watermark_add().Execute();
    	}
    	catch (Expection ex) {
    		System.err.println(ex.toString());
    	}

        try {
			new Watermark_get().Execute();
    	}
    	catch (Expection ex) {
    		System.err.println(ex.toString());
    	}

        try {
			new Watermark_remove().Execute();
    	}
    	catch (Expection ex) {
    		System.err.println(ex.toString());
    	}
    }
}