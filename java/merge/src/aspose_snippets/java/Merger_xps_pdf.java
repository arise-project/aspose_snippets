package aspose_snippets.java;

public class Merger_xps_pdf {
    public static void Execute() {
        var pathSource1 = "../../TestData/test.xps";
        var pathSource2 = "../../TestData/Second/test.xps";

        //xps files can be parsed and loaded as Aspose Document
        var firstDoc = new com.aspose.pdf.Document(pathSource1, new com.aspose.pdf.XpsLoadOptions());
        var secondDoc = new com.aspose.pdf.Document(pathSource2, new com.aspose.pdf.XpsLoadOptions());

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

        //save result pdf to file
        outputDoc.save("Merger_xps_pdf.pdf", com.aspose.pdf.SaveFormat.Pdf);
    }
}
