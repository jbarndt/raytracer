#include <wx/wx.h>
#include <wx/sizer.h>

class wxImagePanel : public wxPanel
{
    wxImage image;
    wxBitmap resized;
    int w, h;

public:
    wxImagePanel(wxFrame* parent, wxString file, wxBitmapType format);

    void paintEvent(wxPaintEvent & evt);
    void paintNow();
    void OnSize(wxSizeEvent& event);
    void render(wxDC& dc);

    DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(wxImagePanel, wxPanel)

EVT_PAINT(wxImagePanel::paintEvent)
EVT_SIZE(wxImagePanel::OnSize)
END_EVENT_TABLE()

wxImagePanel::wxImagePanel(wxFrame* parent, wxString file, wxBitmapType format) :
wxPanel(parent)
{
    image.LoadFile(file, format);
    w = -1;
    h = -1;
}

void wxImagePanel::paintEvent(wxPaintEvent & evt)
{
    wxPaintDC dc(this);
    render(dc);
}

void wxImagePanel::paintNow()
{
    wxClientDC dc(this);
    render(dc);
}

void wxImagePanel::render(wxDC&  dc)
{
    int neww, newh;
    dc.GetSize( &neww, &newh );

    if( neww != w || newh != h )
    {
        resized = wxBitmap( image.Scale( neww, newh /*, wxIMAGE_QUALITY_HIGH*/ ) );
        w = neww;
        h = newh;
        dc.DrawBitmap( resized, 0, 0, false );
    }else{
        dc.DrawBitmap( resized, 0, 0, false );
    }
}

void wxImagePanel::OnSize(wxSizeEvent& event){
    Refresh();
    event.Skip();
}


class MyApp: public wxApp
{

    wxFrame *frame;
    wxImagePanel * drawPane;
public:
    bool OnInit()
    {
        wxInitAllImageHandlers();

        wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
        frame = new wxFrame(NULL, wxID_ANY, wxT("A sphere"), wxPoint(50,50), wxSize(800,600));

        drawPane = new wxImagePanel( frame, wxT("image.jpg"), wxBITMAP_TYPE_JPEG);
        sizer->Add(drawPane, 1, wxEXPAND);

        frame->SetSizer(sizer);

        frame->Show();
        return true;
    }

};

IMPLEMENT_APP(MyApp)
