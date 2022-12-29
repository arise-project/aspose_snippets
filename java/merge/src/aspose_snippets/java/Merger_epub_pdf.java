package aspose_snippets.java;

public class Merger_epub_pdf {
    public static void Execute() {
        String pathSource1 = "../../../../TestData/test.epub";
        String pathSource2 = "../../../../TestData/Second/test.epub";

        com.aspose.pdf.EpubLoadOptions opt1 = new com.aspose.pdf.EpubLoadOptions();
        //use algorithm to prevent content to be truncated
        opt1.setPageSizeAdjustmentMode(com.aspose.pdf.LoadOptions.PageSizeAdjustmentModes.EnlargeRequiredViewportWidthAndDoConversionAgain);
        //usage of margins area during conversion
        opt1.setMarginsAreaUsageMode(com.aspose.pdf.LoadOptions.MarginsAreaUsageModes.PutContentOnMarginAreaIfNecessary);

        //epub files can be parsed and loaded as Aspose Document
        com.aspose.pdf.Document firstDoc = new com.aspose.pdf.Document(pathSource1, opt1);

        com.aspose.pdf.EpubLoadOptions opt2 = new com.aspose.pdf.EpubLoadOptions();
        //use algorithm to prevent content to be truncated
        opt2.setPageSizeAdjustmentMode(com.aspose.pdf.LoadOptions.PageSizeAdjustmentModes.EnlargeRequiredViewportWidthAndDoConversionAgain);
        //usage of margins area during conversion
        opt2.setMarginsAreaUsageMode(com.aspose.pdf.LoadOptions.MarginsAreaUsageModes.PutContentOnMarginAreaIfNecessary);

        com.aspose.pdf.Document secondDoc = new com.aspose.pdf.Document(pathSource2, opt2);

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

        //save result pdf to file
        outputDoc.save("Merger_epub_pdf.pdf", com.aspose.pdf.SaveFormat.Pdf);
    }
}
