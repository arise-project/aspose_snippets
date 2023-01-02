package aspose_snippets.java;

import java.io.IOException;

public class Main {
    public static void main(String[] args) throws Exception {
		new com.aspose.pdf.License().setLicense("../../test.lic");

        try {
			new Watermark_add().Execute();
    	}
    	catch (Exception ex) {
    		System.err.println(ex.toString());
    	}

        try {
			new Watermark_get().Execute();
    	}
    	catch (Exception ex) {
    		System.err.println(ex.toString());
    	}

        try {
			new Watermark_remove().Execute();
    	}
    	catch (Exception ex) {
    		System.err.println(ex.toString());
    	}
    }
}