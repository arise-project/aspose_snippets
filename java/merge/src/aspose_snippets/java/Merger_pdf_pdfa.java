package aspose_snippets.java;

public class Merger_pdf_pdfa {
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

        for(var page : firstDoc.getPages())
        {
            //add page from one document to another directly
            outputDoc.getPages().add(page);
        }

        for(var page : secondDoc.getPages())
        {
            //add page from one document to another directly
            outputDoc.getPages().add(page);
        }

        //save document as specific pdf standard PDFA 3Y
        outputDoc.convert(
                "test.pdf",
                com.aspose.pdf.PdfFormat.PDF_A_3U,
                //delete objects that impossible to convert
                com.aspose.pdf.ConvertErrorAction.Delete);
    }
}
