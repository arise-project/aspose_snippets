import clr

aspose_pdf = clr.AddReference("../../lib/Aspose.PDF.dll")

from Aspose.Pdf import Document

class tex_to_pdf(object):
    def __init__(self,licence_path):
        self.dataDir = "../../TestData"
        if licence_path:
            self.licence_path = licence_path
            self.aspose_license = License()
            self.aspose_license.SetLicense(self.licence_path)

    def exec(self):
        
        pathSource1 = "../../TestData/test.tex"
        pathSource2 = "../../TestData/Second/test.tex"

        opt1 = new Aspose.Pdf.TeXLoadOptions
        #Cancels ligatures in all fonts
        opt1.NoLigatures = False
        #Rasterize scientific formulas to images 
        opt1.RasterizeFormulas = True
        #Print parsing steps details to console output
        opt1.ShowTerminalOutput = True
        
        #TeX files can be parsed and loaded as Aspose Document
        firstDoc = Document(pathSource1, opt1)

        secondDoc = Document(pathSource2,
                new Aspose.Pdf.TeXLoadOptions
                { 
                    //Set ligatures in all fonts
                    NoLigatures = false,
                    //Rasterize scientific formulas to images 
                    RasterizeFormulas = true,
                    //Print parsing steps details to console output
                    ShowTerminalOutput = true
                });

            var outputDoc = new Aspose.Pdf.Document();

            //set less memory usage with unload instead of fast performance
            outputDoc.EnableObjectUnload = true;

            foreach (var page in firstDoc.Pages)
            {
                //add page from one document to another directly
                outputDoc.Pages.Add(page);
            }

            foreach (var page in secondDoc.Pages)
            {
                //add page from one document to another directly
                outputDoc.Pages.Add(page);
            }

            //save result pdf to file
            outputDoc.Save("test.pdf", Aspose.Pdf.SaveFormat.Pdf);
        