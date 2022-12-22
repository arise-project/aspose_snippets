from Aspose.Imaging import Rectangle
from Aspose.Imaging import Image
from Aspose.Pdf import SaveFormat
from Aspose.Pdf import PageSize
from Aspose.Pdf import Document
import clr

aspose_pdf = clr.AddReference("../../lib/Aspose.PDF.dll")
aspose_imaging = clr.AddReference("../../lib/Aspose.Imaging.dll")


class png_to_pdf(object):
    def __init__(self, licence_path):
        self.dataDir = "../../TestData"
        if licence_path:
            self.licence_path = licence_path
            self.aspose_license = License()
            self.aspose_license.SetLicense(self.licence_path)

    def exec(self):

        pathSource1 = "../../TestData/test.png"
        pathSource2 = "../../TestData/Second/test.png"

        # create empty pdf document
        doc = Document

        # set less memory usage with unload instead of fast performance
        doc.EnableObjectUnload = True

        # make list of files with images to merge
        images = [pathSource1, pathSource2]

        for fs in images:
            # add new page to pdf
            page = doc.Pages.Add()

            # setup page size to be A4
            page.SetPageSize(PageSize.A4.Width, PageSize.A4.Height)

            # load image from stream, it supports a lot of formats
            image = Image.Load(fs)
            # read image dimensions to pdf page rectangle
            rect = Rectangle(0, 0, image.Width - 1, image.Height - 1)

            # add image to new pdf page
            page.AddImage(fs, rect)

        # save result pdf to file
        doc.Save("test.pdf", SaveFormat.Pdf)
