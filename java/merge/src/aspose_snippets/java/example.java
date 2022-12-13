package aspose_snippets.java;

public class example {
    public static void Execute() {
        String testID = "com/aspose/pdf/examples/AsposePdf/Annotations/deleteallannotations/";
        String dataDir = "./";
        String outputDir = "./";

        System.out.println("============================");
        System.out.println("Example deleteAllAnnotationsFromPageOfPDFFile start");
        // Open source PDF document
        com.aspose.pdf.Document pdfDocument = new com.aspose.pdf.Document(dataDir + "input.pdf");
        // Delete all annotation
        pdfDocument.getPages().get_Item(1).getAnnotations().delete();
        // Save the update document
        pdfDocument.save(outputDir + "output.pdf");

        System.out.println("Example deleteAllAnnotationsFromPageOfPDFFile end");

        System.out.println("Hello world!");
    }
}
