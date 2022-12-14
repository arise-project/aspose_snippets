package aspose_snippets.java;

public class Merger_pdf_html {
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

        for (com.aspose.pdf.Page page : firstDoc.getPages()) {
            //add page from one document to another directly
            outputDoc.getPages().add(page);
        }

        for (com.aspose.pdf.Page page : secondDoc.getPages()) {
            //add page from one document to another directly
            outputDoc.getPages().add(page);
        }

        com.aspose.pdf.HtmlSaveOptions opt1 = new com.aspose.pdf.HtmlSaveOptions();
        //embed css into a page
        opt1.setPartsEmbeddingMode(com.aspose.pdf.HtmlSaveOptions.PartsEmbeddingModes.EmbedAllIntoHtml);
        //embed images into a page
        opt1.setRasterImagesSavingMode(com.aspose.pdf.HtmlSaveOptions.RasterImagesSavingModes.AsEmbeddedPartsOfPngPageBackground);
        //enhance conversion of documents with backgrounds
        opt1.setAntialiasingProcessing(com.aspose.pdf.HtmlSaveOptions.AntialiasingProcessingType.TryCorrectResultHtml);
        //use fixed layout render
        opt1.setFixedLayout(true);
        outputDoc.save("Merger_pdf_html.html", opt1);
    }
}
