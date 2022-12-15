package aspose_snippets.java;

import com.aspose.pdf.SaveFormat;

public class Merger_eps_pdf {
    public static void Execute() {
        String pathSource1 = "../../../../TestData/test.eps";
        String pathSource2 = "../../../../TestData/Second/test.eps";

        //eps files can be parsed and loaded as Aspose Document
        com.aspose.pdf.Document firstDoc = new com.aspose.pdf.Document(pathSource1, new com.aspose.pdf.PsLoadOptions());
        com.aspose.pdf.Document secondDoc = new com.aspose.pdf.Document(pathSource2, new com.aspose.pdf.PsLoadOptions());

        //create empty pdf document
        com.aspose.pdf.Document outputDoc = new com.aspose.pdf.Document();

        //set less memory usage with unload instead of fast performance
        outputDoc.setEnableObjectUnload(true);

        for(com.aspose.pdf.Page page : firstDoc.getPages())
        {
            //add page from one document to another directly
            outputDoc.getPages().add(page);
        }

        for(com.aspose.pdf.Page page : secondDoc.getPages())
        {
            //add page from one document to another directly
            outputDoc.getPages().add(page);
        }

        //save result pdf to file
        outputDoc.save("test.pdf", SaveFormat.Pdf);
    }
}
