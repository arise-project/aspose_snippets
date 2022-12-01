using Aspose.Pdf;
using Aspose.Pdf.Annotations;

namespace aspose_snippets.net
{
    public static partial class Watermark
    {
        public static void get()
        {
            var pathSource = @"..\..\test.pdf";
            Document document = new Document(pathSource);
            var WatermarkAnnotations = document.Pages[1].Annotations
                .Where(a => a.AnnotationType == AnnotationType.Watermark)
                .Cast<WatermarkAnnotation>();
            
            Console.WriteLine("Watermarkes:");
            foreach (var ca in WatermarkAnnotations)
            {
                Console.WriteLine(ca.Contents);
            }
        }
    }
}
