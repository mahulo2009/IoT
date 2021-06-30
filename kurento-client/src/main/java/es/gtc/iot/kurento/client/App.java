package es.gtc.iot.kurento.client;

import org.kurento.client.Composite;
import org.kurento.client.Dispatcher;
import org.kurento.client.DispatcherOneToMany;
import org.kurento.client.FaceOverlayFilter;
import org.kurento.client.GStreamerFilter;
import org.kurento.client.HttpPostEndpoint;
import org.kurento.client.KurentoClient;
import org.kurento.client.MediaPipeline;
import org.kurento.client.PlayerEndpoint;
import org.kurento.client.RecorderEndpoint;
import org.kurento.client.RtpEndpoint;
import org.kurento.client.WebRtcEndpoint;
import org.kurento.client.ZBarFilter;

/**
 * Hello world!
 *
 */
public class App 
{
    public static void main( String[] args )
    {
        System.out.println( "Hello World!" );

        KurentoClient kurento = KurentoClient.create("ws://localhost:8888/kurento");

        MediaPipeline pipeline = kurento.createMediaPipeline();

        PlayerEndpoint player = new PlayerEndpoint.Builder(pipeline, "http://www.gtc.iac.es/multimedia/netcam/camaraExt.jpg").useEncodedMedia().build();

        HttpPostEndpoint httpEndpoint = new HttpPostEndpoint.Builder(pipeline).build();
        player.connect(httpEndpoint);

        RecorderEndpoint recorderEndpoint = new RecorderEndpoint.Builder(pipeline, "file:///tmp/recording.webm").build();

        System.out.println( "Hello World READY!" );
    }

        /*
        // Protocols and codecs
        WebRtcEndpoint webRtcEndpoint = new WebRtcEndpoint.Builder(pipeline).build();

        HttpPostEndpoint httpPostEndpoint = new HttpPostEndpoint.Builder(pipeline).build();

        RtpEndpoint rtpEndpoint = new RtpEndpoint.Builder(pipeline).build();

        // Media repository
        PlayerEndpoint playerEndpoint = new PlayerEndpoint.Builder(pipeline, "http://www.gtc.iac.es/multimedia/netcam/camaraExt.jpg").build();

        

        // Filters
        FaceOverlayFilter faceOverlayFilter = new FaceOverlayFilter.Builder(pipeline).build();

        ZBarFilter zBarFilter = new ZBarFilter.Builder(pipeline).build();

        GStreamerFilter gstreamerFilter = new GStreamerFilter.Builder(pipeline, "videoflip method=4").build();

        // Group communications
        Composite composite = new Composite.Builder(pipeline).build();

        Dispatcher dispatcher = new Dispatcher.Builder(pipeline).build();

        DispatcherOneToMany dispatcherOneToMany = new DispatcherOneToMany.Builder(pipeline).build();

        
        */

    
}

/*

    PlayerEndpoint player = new PlayerEndpoint.Builder(pipeline, "http://" + getTestFilesHttpPath() + "/video/format/small.webm").useEncodedMedia().build();
    HttpPostEndpoint httpEndpoint = new HttpPostEndpoint.Builder(pipeline).build();
    player.connect(httpEndpoint);
    String url = httpEndpoint.getUrl();
    // End pipeline creation
    // Explicit transaction
    Transaction tx = pipeline.beginTransaction();
    player.play(tx);
    TFuture<String> fUrl = httpEndpoint.getUrl(tx);
    pipeline.release(tx);
    tx.commit();
    // End explicit transaction
    assertThat(url, is(fUrl.get()));
*/