package aspose_snippets.java;

import com.aspose.pdf.License;

public class Main {
    public static void main(String[] args) throws Exception {
        new License().setLicense("../../test.lic");

        try {
			new Split_HTML().Execute();
    	}
    	catch (Exception ex) {
    		System.err.println(ex.toString());
    	}

        try {
			new Split_PDF().Execute();
    	}
    	catch (Exception ex) {
    		System.err.println(ex.toString());
    	}

        try {
			new Split_TXT().Execute();
    	}
    	catch (Exception ex) {
    		System.err.println(ex.toString());
    	}
    }
}