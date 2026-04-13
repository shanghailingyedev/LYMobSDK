#
# Be sure to run `pod lib lint LYMobSDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'LYMobSDK'
  s.version          = '1.0.3'
  s.summary          = 'LYMobSDK init'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'git@github.com:shanghailingyedev/LYMobSDK.git'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'shanghailingyedev' => 'shanghailingye_dev@163.com' }
  s.source           = { :git => 'git@github.com:shanghailingyedev/LYMobSDK.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '10.0'
  
  s.resource = ['LYMobSDK/Assets/*.bundle']
  s.vendored_libraries = 'LYMobSDK/Classes/*.a'
  s.vendored_frameworks = 'LYMobSDK/Classes/*.{xcframework,framework}'
  
  s.frameworks = ["Foundation", "UIKit", "MobileCoreServices", "CoreGraphics", "Security","AppTrackingTransparency", "SystemConfiguration", "CoreTelephony", "AdSupport", "CoreData", "StoreKit", "AVFoundation", "MediaPlayer", "CoreMedia", "WebKit", "Accelerate", "CoreLocation", "AVKit", "MessageUI", "QuickLook", "AudioToolBox", "JavaScriptCore", "CoreMotion", "Photos"]
  
  s.static_framework = true
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  
end
