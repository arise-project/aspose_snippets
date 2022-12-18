package aspose_snippets.java;

public class Merger_pdf_tex {
    public static void Execute() {
        var pathSource1 = "../../TestData/test.pdf";
        var pathSource2 = "../../TestData/Second/test.pdf";

        //read pdf file to Aspose Document
        var firstDoc = new com.aspose.pdf.Document(pathSource1);
        var secondDoc = new com.aspose.pdf.Document(pathSource2);

        //create empty pdf document
        var outputDoc = new com.aspose.pdf.Document();

        //set less memory usage with unload instead of fast performance
        outputDoc.setEnableObjectUnload(true);

        for (var page : firstDoc.getPages()) {
            //add page from one document to another directly
            outputDoc.getPages().add(page);
        }

        for (var page : secondDoc.getPages()) {
            //add page from one document to another directly
            outputDoc.getPages().add(page);
        }

        var opt1 = new com.aspose.pdf.TeXSaveOptions();
        //save parsed artifacts, for example images to a directory
        opt1.setOutDirectoryPath("./test");
        outputDoc.save("test.tex", opt1);
    }
}
