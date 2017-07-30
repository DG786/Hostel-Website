if (self.CavalryLogger) { CavalryLogger.start_js(["jTf3G"]); }

__d('MessengerQuickCam',['Arbiter','Button','Dialog','MercuryMessageObject','MercuryMessageActions','MercurySourceType'],function a(b,c,d,e,f,g){if(c.__markCompiled)c.__markCompiled();function h(i,j,k,l,m,n){'use strict';h.destroyInstance();h.instance=this;this.swfID=k;this.arbiterToken=c('Arbiter').subscribe(i,this.swfCallback.bind(this));this.success_event=j;this.send_button=l;this.setEnabled(false);this.thread_id=m;this.viewer=n.toString();this.messageBuilder=c('MercuryMessageObject').getForFBID(this.viewer);this.messageActions=c('MercuryMessageActions').getForFBID(this.viewer);}h.prototype.swfCallback=function(i,j){'use strict';var k=i.split('/'),l=k[3];if(l===this.swfID){var m=k[2];if(m==='reset'){this.setEnabled(false);}else if(m==='save'){this.setEnabled(true);}else if(m==='upload_success'){if(j)this.send(j);}else if(m==='upload_error')this.setEnabled(true);}};h.prototype.send=function(i){'use strict';var j=this.messageBuilder.constructAttachmentMessageObject(c('MercurySourceType').CHAT_WEB,this.thread_id),k={message_source:'camera'};j.message_source_data=JSON.stringify(k);j.body='';j.has_attachment=true;j.photo_fbids=[i];this.messageActions.send(j);c('Arbiter').inform(this.success_event,{isLoading:1},c('Arbiter').BEHAVIOR_STATE);this.destroy();};h.prototype.destroy=function(){'use strict';this.arbiterToken.unsubscribe();h.instance=null;};h.prototype.setEnabled=function(i){'use strict';var j=c('Dialog').getCurrent();if(j||this.send_button){var k=this.send_button;k&&c('Button').setEnabled(k,i);}};h.destroyInstance=function(){'use strict';h.instance&&h.instance.destroy();};h.instance=null;f.exports=h;},null);
__d('MessengerQuickCamConfig',[],function a(b,c,d,e,f,g){if(c.__markCompiled)c.__markCompiled();var h={success:'messenger/quick_cam/success',max_video_time:120000,progress_increment:.01};f.exports=h;},null);
__d('MessengerQuickCamDialogController',['Arbiter','Button','DialogX','MessengerQuickCam','MessengerQuickCamConfig','$','tidyEvent'],function a(b,c,d,e,f,g){if(c.__markCompiled)c.__markCompiled();function h(){var j=c('DialogX').getTopmostLayer();if(!j)return;j.subscribeOnce('hide',h);j.hide();}function i(j,k,l,m,n,o,p){var q=new (c('MessengerQuickCam'))(k,c('MessengerQuickCamConfig').success,m,l,o,p);c('tidyEvent')(j.subscribe(['cancel','confirm','hide'],function(r){if(r==='cancel'){c('Arbiter').inform('swf/photo_camera/cancel/');}else if(r==='hide'){q.destroy();}else{if(c('Button').isEnabled(l))c('Arbiter').subscribeOnce(c('MessengerQuickCamConfig').success,h,c('Arbiter').SUBSCRIBE_NEW);c('$')(m).upload(n);c('Button').setEnabled(l,false);}}));}f.exports=i;},null);