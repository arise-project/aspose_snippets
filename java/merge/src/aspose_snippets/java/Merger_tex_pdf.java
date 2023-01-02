package aspose_snippets.java;

public class Merger_tex_pdf {
    public static void Execute() {
        String pathSource1 = "../../TestData/test.tex";
        String pathSource2 = "../../TestData/Second/test.tex";

        com.aspose.pdf.TeXLoadOptions opt1 = new com.aspose.pdf.TeXLoadOptions();

        //Cancels ligatures in all fonts
        opt1.setNoLigatures(false);
        //Rasterize scientific formulas to images
        opt1.setRasterizeFormulas(true);
        //Print parsing steps details to console output
        opt1.setShowTerminalOutput(true);

        //TeX files can be parsed and loaded as Aspose Document
        com.aspose.pdf.Document firstDoc = new com.aspose.pdf.Document(pathSource1, opt1);

        com.aspose.pdf.TeXLoadOptions opt2 = new com.aspose.pdf.TeXLoadOptions();

        //Set ligatures in all fonts
        opt2.setNoLigatures(false);
        //Rasterize scientific formulas to images
        opt2.setRasterizeFormulas(true);
        //Print parsing steps details to console output
        opt2.setShowTerminalOutput(true);
        com.aspose.pdf.Document secondDoc = new com.aspose.pdf.Document(pathSource2, opt2);

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
        outputDoc.save("Merger_tex_pdf.pdf", com.aspose.pdf.SaveFormat.Pdf);
    }
}
