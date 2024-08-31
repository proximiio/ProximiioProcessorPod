#
# Be sure to run `pod lib lint ProximiioProcessor.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'ProximiioProcessor'
  s.version          = '0.23.0'
  s.summary          = 'Proximi.io position processors.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
Proximi.io position processors.                       
DESC

  s.homepage         = 'https://github.com/proximiio/ProximiioProcessorPod'
  s.license          = { :type => 'commercial', :file => 'LICENSE' }
  s.author           = { 'Matteo Crippa' => 'matteocrippa@users.noreply.github.com' }
  s.source           = { :git => 'https://github.com/proximiio/ProximiioProcessorPod.git', :tag => s.version.to_s }

  s.ios.deployment_target = '13.0'

  s.dependency 'Proximiio'
  s.dependency 'SwiftyJSON'

  s.vendored_frameworks = 'ProximiioProcessor.xcframework'
end
