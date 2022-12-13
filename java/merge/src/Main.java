import com.aspose.pdf.Document;

public class Main {
    public static void main(String[] args)
    {
        String testID = "com/aspose/pdf/examples/AsposePdf/Annotations/deleteallannotations/";
        String dataDir = "./";
        String outputDir = "./";

        System.out.println("============================");
        System.out.println("Example deleteAllAnnotationsFromPageOfPDFFile start");
        // Open source PDF document
        Document pdfDocument = new Document(dataDir + "input.pdf");
        // Delete all annotation
        pdfDocument.getPages().get_Item(1).getAnnotations().delete();
        // Save the update document
        pdfDocument.save(outputDir + "output.pdf");

        System.out.println("Example deleteAllAnnotationsFromPageOfPDFFile end");

        System.out.println("Hello world!");
    }
}