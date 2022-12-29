package aspose_snippets.java;

public class Merger_pdf_docx {
    public static void Execute() {
        String pathSource1 = "../../TestData/test.pdf";
        String pathSource2 = "../../TestData/Second/test.pdf";

        //read pdf file to Aspose Document
        com.aspose.pdf.Document firstDoc = new com.aspose.pdf.Document(pathSource1);
        com.aspose.pdf.Document secondDoc = new com.aspose.pdf.Document(pathSource2);

        //create empty pdf document
        com.aspose.pdf.Document outputDoc = new com.aspose.pdf.Document();

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

        var opt1 = new com.aspose.pdf.DocSaveOptions();
        //use docx format
        opt1.setFormat(com.aspose.pdf.DocSaveOptions.DocFormat.DocX);
        //make document editable flow and recognize of tables
        opt1.setMode(com.aspose.pdf.DocSaveOptions.RecognitionMode.EnhancedFlow);

        outputDoc.save("Merger_pdf_docx.docx", opt1);
    }
}
