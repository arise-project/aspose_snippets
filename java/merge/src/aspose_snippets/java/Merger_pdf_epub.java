package aspose_snippets.java;

public class Merger_pdf_epub {
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

        com.aspose.pdf.EpubSaveOptions opt1 = new com.aspose.pdf.EpubSaveOptions();
        //keep the logical structure of transformed document
        opt1.setContentRecognitionMode(com.aspose.pdf.EpubSaveOptions.RecognitionMode.PdfFlow);
        outputDoc.save("test.epub", opt1);
    }
}
